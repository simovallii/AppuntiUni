package it.unipr.scuola;

import java.util.HashSet;
import java.util.Set;

public class AppelloEsame {
	
	private final String nome;
	private final int anno;
	private final Set<Immatricolabile> iscritti;
	
	public AppelloEsame(String nome, int anno) {
		this.nome = nome;
		this.anno = anno;
		this.iscritti = new HashSet<Immatricolabile>();
	}
	
	public void add(Immatricolabile studente) throws AppelloEsameException{
		if(iscritti.size() == 100)
			throw new AppelloEsameException("appello pieno di iscritti");
		
		if(iscritti.contains(studente)) {
			throw new AppelloEsameException("studente già iscritto");
		}
		int ord = 0;
		int lav = 0;
		
		for(Immatricolabile s : iscritti) {
			if(s instanceof StudenteOrdinario)
				ord++;
			else if(s instanceof StudenteLavoratore)
				lav++;
		}
		
		if (ord < 50 && lav < 50)
			iscritti.add(studente);
		else
			throw new AppelloEsameException("limite di studenti lavoratori e/o ordinari raggiunto"); // sbagliato
	}
	
	public boolean equals(Object obj) {
		if(this == obj)
			return true;
		if(obj == null)
			return false;
		if(this.getClass() != obj.getClass())
			return false;
		
		AppelloEsame other = (AppelloEsame) obj;
		return this.nome.equals(other.nome) && this.anno == other.anno && this.iscritti.equals(other.iscritti);
	}
}
