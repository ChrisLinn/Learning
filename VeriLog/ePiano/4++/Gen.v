module Gen(signal,clk1M,out);
	input [4:0] signal;
	input clk1M;
	output out;
	wire [4:0] signal;
	reg [20:0] ti;
	wire clk1M;
	reg out;
	initial
		begin  
    		ti=0;
			out=0;
		end
	always @ (posedge clk1M)
			begin
				ti=ti+1;
				case(signal)
					5'b00000:
						if(ti<500000/523)		out=0;
						else if(ti>1000000/523) ti=0;
						else if(ti>500000/523) 	out=1;
					5'b00001:
						if(ti<500000/587)		out=0;
						else if(ti>1000000/587) ti=0;
						else if(ti>500000/587) 	out=1;
					5'b00010:
						if(ti<500000/659)		out=0;
						else if(ti>1000000/659) ti=0;
						else if(ti>500000/659) 	out=1;
					5'b00011:
						if(ti<500000/698)		out=0;
						else if(ti>1000000/698) ti=0;
						else if(ti>500000/698) 	out=1;
					5'b00100:
						if(ti<500000/784)		out=0;
						else if(ti>1000000/784) ti=0;
						else if(ti>500000/784) 	out=1;
					5'b00101:
						if(ti<500000/880)		out=0;
						else if(ti>1000000/880) ti=0;
						else if(ti>500000/880) 	out=1;
					5'b00110:
						if(ti<500000/998)		out=0;
						else if(ti>1000000/998) ti=0;
						else if(ti>500000/998) 	out=1;
					5'b01000:
						if(ti<1000000/523)		out=0;
						else if(ti>2000000/523) ti=0;
						else if(ti>1000000/523) out=1;
					5'b01001:
						if(ti<1000000/587)		out=0;
						else if(ti>2000000/587) ti=0;
						else if(ti>1000000/587) out=1;
					5'b01010:
						if(ti<1000000/659)		out=0;
						else if(ti>2000000/659) ti=0;
						else if(ti>1000000/659) out=1;
					5'b01011:
						if(ti<1000000/698)		out=0;
						else if(ti>2000000/698) ti=0;
						else if(ti>1000000/698) out=1;
					5'b01100:
						if(ti<1000000/784)		out=0;
						else if(ti>2000000/784) ti=0;
						else if(ti>1000000/784) out=1;
					5'b01101:
						if(ti<1000000/880)		out=0;
						else if(ti>2000000/880) ti=0;
						else if(ti>1000000/880) out=1;
					5'b01110:
						if(ti<1000000/998)		out=0;
						else if(ti>2000000/998) ti=0;
						else if(ti>1000000/998) out=1;
					5'b10000:
						if(ti<250000/523)		out=0;
						else if(ti>500000/523) 	ti=0;
						else if(ti>250000/523) 	out=1;
					5'b10001:
						if(ti<250000/587)		out=0;
						else if(ti>500000/587) 	ti=0;
						else if(ti>250000/587) 	out=1;
					5'b10010:
						if(ti<250000/659)		out=0;
						else if(ti>500000/659) 	ti=0;
						else if(ti>250000/659) 	out=1;
					5'b10011:
						if(ti<250000/698)		out=0;
						else if(ti>500000/698) 	ti=0;
						else if(ti>250000/698) 	out=1;
					5'b10100:
						if(ti<250000/784)		out=0;
						else if(ti>500000/784) 	ti=0;
						else if(ti>250000/784) 	out=1;
					5'b10101:
						if(ti<250000/880)		out=0;
						else if(ti>500000/880) 	ti=0;
						else if(ti>250000/880) 	out=1;
					5'b10110:
						if(ti<250000/998)		out=0;
						else if(ti>500000/998) 	ti=0;
						else if(ti>250000/998) 	out=1;
					5'b11111:
						out=0;
				endcase
	end
endmodule