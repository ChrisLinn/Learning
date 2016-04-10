module BugKiller (in,clk1M,out);
	input  in,clk1M;
	output out;
	wire in,clk1M;
	reg out;
	reg [19:0] ti;
	reg [2:0] sta;
	initial
		begin  
    		ti=0;
			sta=3'b000;
		end
	always @ (posedge clk1M)
		begin
			ti=ti+1;	
			case(sta)
				3'b000 :
							begin
								if(in==1)
									sta=3'b000;
								else 
									begin
										sta=3'b001;
										ti=0;
									end
							end
				3'b001 :
							begin
								if(ti<10000)
									sta=3'b001;
								else	
									sta=3'b010;
							end
				3'b010 :
							begin
								if(in==1)
									sta=3'b000;
								else
									sta=3'b011;
							end
				3'b011 :
							begin
								if(in==1)
									begin
										sta=3'b100;
										ti=0;
									end
								else
									sta=3'b011;
							end						
				3'b100 :
							begin
								if(ti<200000)
									sta=3'b100;
								else
										sta=3'b101;
							end
				3'b101 :
							begin
								if(in==1)
									sta=3'b000;
								else
									sta=3'b011;
							end
			endcase
			case(sta)
				3'b000 : out=1;
				3'b001 : out=1;
				3'b010 : out=1;
				3'b011 : out=0;					
				3'b100 : out=0;
				3'b101 : out=0;
			endcase
		end
		
endmodule