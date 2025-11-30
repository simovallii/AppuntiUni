package it.unipr.bibio;

public class Libro extends Pubblicazione {
	 
	private String autore;
	private int nPag;
	
	public Libro(String titolo, String codiceISBN, String autore, int nPag){
		
		super(titolo, codiceISBN);
		this.autore = autore;
		this.nPag = nPag;
	}
}
