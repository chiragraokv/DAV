module q1(F, A, B, C, D);
	input A, B, C, D;
	output F;
	not(An, A);
	not(Bn, B);
	not(Cn, C);
	not(Dn, D);
	and(o1, An, B);
	and(o2, B, Cn, Dn);
	and(o3, C, D);
	and(o4, C, Bn);
	or(F, o1, o2, o3, o4);
endmodule
	
