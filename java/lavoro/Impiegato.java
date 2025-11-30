package it.unipr.lavoro;

public abstract class Impiegato {
	
	private final String nome;
	private final String cognome;
	private final int ore;
	
	public Impiegato(String nome, String cognome, int ore) {
		this.nome = nome;
		this.cognome = cognome;
		this.ore = ore;
	}
	public String getNome() {
		return this.nome;
	}
	public String getCognome() {
		return this.cognome;
	}
	public int getOre() {
		return this.ore;
	}
	
	public abstract double getStipendioAnnuale();
	
	public boolean equals(Object obj) {
		if(this == obj)
			return true;
		if(obj == null)
			return false;
		if(this.getClass() != obj.getClass())
			return false;
		
		Impiegato other = (Impiegato) obj;
		return this.nome.equals(other.nome) && this.cognome.equals(other.cognome) && this.ore == other.ore;
	}
}
