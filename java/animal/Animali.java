package it.unipr.animal;

public class Animali {
	
	protected String nome;
	protected int eta;
	
	public Animali() {
		this("nessun animale", 0);
	}
	public Animali(String nome, int eta) {
		this.nome = nome;
		this.eta = eta;
		}
	
	public String toString () {
		return nome + ", " + eta;
	}
	
	public boolean equals(Object obj) {
		if (this == obj) 
			return true;
		if (obj == null)
			return false;
		if (this.getClass() !=  obj.getClass())
			return false;
		
		Animali other = (Animali) obj;
		
		return this.nome.equals(other.nome) && this.eta == other.eta;
	}
}
