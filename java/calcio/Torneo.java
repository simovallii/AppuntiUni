package it.unipr.calcio;

import java.util.HashSet;
import java.util.Set;
import java.util.Vector;

public class Torneo {
	
	private final Vector<Partita> torneo;
	
	public Torneo() {
		this.torneo = new Vector<Partita>();
	}
	
	public void aggiungiPartita (Partita newPartita) throws TorneoException{
		
		if(torneo.contains(newPartita))
			throw new TorneoException("Partita già esistente");
		torneo.add(newPartita);
	}
	
	public Set<Partita> getPartiteinData(String data){
		
			Set result = new HashSet<Partita>();
			for(Partita p : torneo) {
				if (p.getData().equals(data))
					result.add(p);
			}
			
			return result;
	}
}
