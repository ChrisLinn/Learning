module AngryPuppy (in1,in2,in3,in4,in5,in6,in7,hKey,lKey,signal);
	input  in1,in2,in3,in4,in5,in6,in7,hKey,lKey;
	output [4:0] signal;
	wire in1,in2,in3,in4,in5,in6,in7,hKey,lKey;
	reg [4:0] signal;
	always @(in1 or in2 or in3 or in4 or in5 or in6 or in7 or hKey or lKey)
		begin
			if(!hKey)
				begin
					if(!in1)      signal<=5'b10000;
					else if(!in2) signal<=5'b10001;
					else if(!in3) signal<=5'b10010;
					else if(!in4) signal<=5'b10011;
					else if(!in5) signal<=5'b10100;
					else if(!in6) signal<=5'b10101;
					else if(!in7) signal<=5'b10110;
					else 		  signal<=5'b11111;
				end
			else if(!lKey)
				begin
					if(!in1)      signal<=5'b01000;
					else if(!in2) signal<=5'b01001;
					else if(!in3) signal<=5'b01010;
					else if(!in4) signal<=5'b01011;
					else if(!in5) signal<=5'b01100;
					else if(!in6) signal<=5'b01101;
					else if(!in7) signal<=5'b01110;
					else 		  signal<=5'b11111;
				end
			else
				begin
					if(!in1) 	  signal<=5'b00000;
					else if(!in2) signal<=5'b00001;
					else if(!in3) signal<=5'b00010;
					else if(!in4) signal<=5'b00011;
					else if(!in5) signal<=5'b00100;
					else if(!in6) signal<=5'b00101;
					else if(!in7) signal<=5'b00110;
					else 		  signal<=5'b11111;
				end
				
		end
endmodule