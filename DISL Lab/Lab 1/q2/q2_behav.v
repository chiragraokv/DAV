module q2_behav(f, g, a, b, c, d);
	input a, b, c, d;
	output f, g;
	assign f = ((~(a & b)) ^ d ^ c);
	assign g = ~(b | c | d);
endmodule
