module q2_a(F, A, B, C, D);
	input A, B, C, D;
	output F;
	not(Bn, B);
	or(o1, B, C);
	or(o2, Bn, D);
	and(F, o1, o2);
endmodule
