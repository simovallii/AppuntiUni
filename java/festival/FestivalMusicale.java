package it.unipr.festival;

import java.util.HashSet;
import java.util.Set;

public class FestivalMusicale {
	
	private final Set<Esibizione> esibizioni;
	
	public FestivalMusicale() {
		this.esibizioni = new HashSet<Esibizione>();
	}
	
	public void add (Esibizione esibizione)throws EsibizioneEsistenteException {
		
		if(esibizioni.contains(esibizione))
			throw new EsibizioneEsistenteException("esibizione già presente");
		
		esibizioni.add(esibizione);
	}
	
	public Set<Partecipante> getPartecipantiInData(String data) {
		
		Set<Partecipante> result = new HashSet<Partecipante>();
		
		for (Esibizione es : esibizioni) {
			
			if (es.getDataOra().equals(data))
				result.add(es.getPartecipante());
		}
		return result;
			
	}
	
	public int numeroEsibizioniRegistrate() {
		
		return esibizioni.size();
	}
}
