package it.unipr.bibio;

public class Rivista extends Pubblicazione{
	private int meseUscita;
	private int annoUscita;
	private String editore;
	
	public Rivista(String titolo, String codiceISBN, int meseUscita, int annoUscita) {
		super(titolo, codiceISBN);
		this.meseUscita = meseUscita;
		this.annoUscita = annoUscita;
	} 
}

