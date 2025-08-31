module q3(f, x1, x2, x3, x4);
	input x1, x2, x3, x4;
	output f;
	and(o1, x1, x2, x4);
	and(o2, x1, x3, x4);
	and(o3, x1, x2, x3);
	and(o4, x2, x3, x4);
	or(f, o1, o2, o3, o4);
endmodule
