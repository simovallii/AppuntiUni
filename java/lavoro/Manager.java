package it.unipr.lavoro;

import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

public class Manager extends Impiegato implements Comparable<Manager>{
	
	private static double importoOrario = 25.50;
	private final Set<Impiegato> team;
	
	public Manager(String nome, String cognome, int ore) {
		super(nome, cognome, ore);
		this.team = new HashSet<Impiegato>();
	}
	
	public double getStipendioAnnuale() {
		double stipendio = 0;
		
		stipendio = importoOrario * this.getOre();
		return stipendio;
	}
	
	public void aggiungiAlTeam(Impiegato imp) throws TeamManagerException{
		
		if(imp instanceof Manager)
			throw new TeamManagerException("impossibile aggiungere un manager al team");
		if(imp.getOre() < 20)
			throw new TeamManagerException("ore insufficienti");
		
		for(Impiegato i : team) {
			if(i.equals(imp))
			throw new TeamManagerException("Impiegato già presente");
		}
		
		team.add(imp);
	}
	public int compareTo(Manager other) {
		return Integer.compare(this.team.size(), other.team.size());
	}
}
