package it.unipr.festival;

import java.util.Objects;

public class Band extends Partecipante{
	
	private final int numeroComponenti;
	
	public Band(String nome, int anniAttivita, int numeroComponenti) {
		
		super(nome, anniAttivita);
		this.numeroComponenti = numeroComponenti;
	}
	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = super.hashCode();
		result = prime * result + Objects.hash(numeroComponenti);
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
		
		Band other = (Band) obj;
		return super.equals(other) && this.numeroComponenti == other.numeroComponenti;
	}
	
	public String toString() {
		
		return super.toString() + ", numero dei componenti:" + numeroComponenti; 
	}
	
	
}
