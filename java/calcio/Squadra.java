package it.unipr.calcio;

public class Squadra {
	
	private String nomeSquadra;
	private Calciatore [] team;
	
	public Squadra(Calciatore[] team, String nomwSquadra) throws TorneoException {
		if(team.length > 22)
			throw new TorneoException("Troppi calciatori in rosa");
		
		int att = 0;
		int por = 0; 
		for(Calciatore c : team ) {
			if(c instanceof Attaccante)
				att++;
			else if(c instanceof Portiere)
				por++;
		}
		
		if(att < 5 && por < 3)
		this.team = team;
		this.nomeSquadra = nomeSquadra;
	}
	
	
	public boolean equals(Object obj) {
		if(this == obj)
			return true;
		if(obj == null)
			return false;
		if(this.getClass() != obj.getClass())
			return false;
		
		Squadra other = (Squadra) obj;
		return this.nomeSquadra.equals(other.nomeSquadra) && this.team.equals(other.team);
	}
	
	
}
