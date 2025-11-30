package it.unipr.scuola;

public class StudenteLavoratore implements Immatricolabile{

	private final String matricola;
	private final String azienda;
	
	public StudenteLavoratore(String matricola, String azienda) {
		this.matricola = matricola;
		this.azienda = azienda;
	}
	public String getMatricola() {
		return matricola;
	}
	public boolean equals(Object obj) {
		if(this == obj)
			return true;
		if(obj == null)
			return false;
		if(this.getClass() != obj.getClass())
			return false;
		
		StudenteLavoratore other = (StudenteLavoratore) obj;
		return this.getMatricola().equals(other.getMatricola()) && this.azienda.equals(other.azienda);
	}
}
