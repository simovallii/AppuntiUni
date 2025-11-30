package it.unipr.festival;

import java.util.Objects;

public abstract class Partecipante {
	
	protected final String nome;
	protected final int anniAttivita;
	
	public Partecipante(String nome, int anniAttivita) {
		this.nome = nome;
		this.anniAttivita = anniAttivita;
	}
	
	@Override
	public int hashCode() {
		return Objects.hash(anniAttivita, nome);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		
		Partecipante other = (Partecipante) obj;
		return anniAttivita == other.anniAttivita && Objects.equals(nome, other.nome);
	}
	
	public String toString() {  // se non lo voglio ridefinire nelle altre classi metto final
		return "nome: " + nome + ", anni di attività" + anniAttivita;
	}
}
