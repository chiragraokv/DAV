module q2_struct(f, g, a, b, c, d);
	input a, b, c, d;
	output f, g;
	nand(o1, a, b);
	nor(g, d, c, b);
	xor(f, d, o1, c);
endmodule
