package it.unipr.scuola;

public class StudenteOrdinario implements Immatricolabile{
	
	private final String matricola;
	private final String scuola;
	
	public StudenteOrdinario(String matricola, String scuola) {
		this.matricola = matricola;
		this.scuola = scuola;
	}
	public String getMatricola() {
		return this.matricola;
	}
	
	public boolean equals(Object obj) {
		if(this == obj)
			return false;
		if(obj == null)
			return false;
		if(this.getClass() != obj.getClass())
			return false;
		
		StudenteOrdinario other = (StudenteOrdinario) obj;
		return this.getMatricola().equals(other.getMatricola());
	}

}
