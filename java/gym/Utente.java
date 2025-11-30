package it.unipr.gym;

public class Utente {
	private final String nome;
	private  final String cognome;
	
	public Utente(String nome, String cognome) {
		
		this.nome = nome;
		this.cognome = cognome;
		
	}
	
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if(obj == null)
			return false;
		if(this.getClass() != obj.getClass())
			return false;
		
		Utente other = (Utente) obj;
		return other.nome.equals(other.nome) && other.cognome.equals(other.cognome);
	}
	
	public String toString() {
		return this.nome.toString() + this.cognome.toString();
	}
}
