module q2(F, A, B, C, D);
	input A, B, C, D;
	output F;
	nor n1(Dn, D, D);
	nor n2(o1, B, D);
	nor n3(o2, B, C);
	nor n4(o3, A, C, Dn);
	nor n5(o4, o3, o2, o1);
	nor n6(F, o4, o4);
endmodule
