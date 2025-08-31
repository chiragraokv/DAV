module q1_b(F, A, B, C, D);
	input A, B, C, D;
	output F;
	not(Bn, B);
	not(Cn, C);
	not(Dn, D);
	and(o1, B, Cn, Dn);
	and(o2, Bn, D);
	and(o3, Bn, C);
	or(F, o1, o2, o3);
endmodule
