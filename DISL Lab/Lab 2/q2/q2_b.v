module q2_b(F, A, B, C, D);
	input A, B, C, D;
	output F;
	not(An, A);
	not(Bn, B);
	not(Cn, C);
	not(Dn, D);
	or(o1, D, A, Bn);
	or(o2, Cn, An, B);
	or(o3, C, D, Bn);
	or(o4, An, B, Dn);
	and(F, o1, o2, o3, o4);
endmodule
