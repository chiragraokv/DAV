module q1_struct (f, a, b, c, d);
	input a, b, c, d;
	output f;
	and(o1, a, b);
	and(o2, a, b);
	or(o3, o1, c);
	or(o4, o2, c);
	not(o3_, o3);
	and(o5, o3_, d);
	or(o6, d, o4);
	and(f, o5, o6);
endmodule 
