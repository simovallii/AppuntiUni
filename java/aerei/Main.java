package it.unipr.aerei;

public class Main {
	
	public static void main(String[] args) {
		Aereo a1 = new Aereo();
	Aereo a2 = new Aereo();
	
	a1.decollo();
	a1.crociera();
	a1.atterraggio();
	a1.atterrato();
	
	a2.decollo();
	a2.decollo();
	a2.atterraggio();
	a2.atterrato();
	System.out.println(Aereo.getNvoli());
}
}
