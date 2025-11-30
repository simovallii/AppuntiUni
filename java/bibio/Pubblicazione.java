package it.unipr.bibio;

public class Pubblicazione {
	
	private String titolo; 
	private String codiceISBN;
	
	Pubblicazione(String Titolo, String codiceISBN){
		this.titolo = titolo;
		this.codiceISBN = codiceISBN;
	}
	
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if(obj == null)
			return false;
		if(!(obj instanceof Pubblicazione))
			return false;
		
		Pubblicazione other = (Pubblicazione) obj;
		return other.codiceISBN == this.codiceISBN; 
	}
}
