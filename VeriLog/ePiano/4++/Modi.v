module Modi(in,out);
	input in;
	output out;
	wire in;
	reg out;
	initial
		begin  
			out<=0;
		end
	always @ (posedge in)
			begin
				out<=1-out;
			end
endmodule	