package it.unipr.festival;

import java.util.Objects;

public class Solista extends Partecipante{
	
	private final String strumentoPrincipale;
	
	public Solista(String nome, int anniattivita, String strumentoPrincipale) {
		
		super(nome, anniattivita);
		this.strumentoPrincipale = strumentoPrincipale;
	}
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = super.hashCode();
		result = prime * result + Objects.hash(strumentoPrincipale);
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (!super.equals(obj))
			return false;
		if (getClass() != obj.getClass())
			return false;
		Solista other = (Solista) obj;
		return super.equals(other) && this.strumentoPrincipale.equals(other.strumentoPrincipale);
	}
	
	public String toString() {
		
		return super.toString() + ", numero dei componenti:" + strumentoPrincipale; 
	}
	
}
