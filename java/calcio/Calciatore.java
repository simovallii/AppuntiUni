package it.unipr.calcio;

public abstract class Calciatore implements Comparable<Calciatore>{
	private final String nome;
	private final String  cognome;
	private final int nmaglia;
	
	public Calciatore(String nome, String cognome, int nmaglia){
		
		this.nome = nome;
		this.cognome = cognome;
		this.nmaglia = nmaglia;
	}
	
	public boolean equals(Object obj) {
		
		if(this == obj)
			return true;
		if(obj == null)
			return false;
		if(this.getClass() != obj.getClass())
			return false; 
		
		Calciatore other = (Calciatore) obj;
		return this.nome.equals(other.nome) && this.cognome.equals(other.cognome) && this.nmaglia == other.nmaglia;
	}
	
	public int compareTo(Calciatore other) {
		
		return Integer.compare(this.nmaglia, other.nmaglia);
	}
}
