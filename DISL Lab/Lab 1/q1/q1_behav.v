module q1_behav(f, a, b, c, d);
	input a, b, c, d;
	output f;
	assign f = ((~((a & b) | c) & d) & (((a & b) | c) | d));
endmodule
