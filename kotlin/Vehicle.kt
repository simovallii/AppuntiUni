abstract class Vehicle(val maxSpeed : Double, val category : VehicleCategory) {
    abstract fun energyType(): String
    fun info(){
        println("max speed: $maxSpeed")
    }
}

interface Rechargheable {
    fun recharge()
}

enum class VehicleCategory {CITY, SUV, TRUCK}

class ElectricCar(maxSpeed: Double, category : VehicleCategory): Vehicle(maxSpeed, category), Rechargheable{

    override fun energyType(): String {
        return "Elettricita'"
    }
    override fun recharge()  {
        println("Ricarica effettuata!!" )
    }
}
class DieselCar(maxSpeed: Double, category: VehicleCategory): Vehicle(maxSpeed, category){
    override fun energyType(): String {
        return "Diesel"
    }
}

object FleetManager{
    val lista = mutableListOf<Vehicle>()

    fun addVehicle(vehicle: Vehicle) {
        lista.add(vehicle)
    }
    fun fastVechicleCount() : Int {
        return lista.count {it.maxSpeed > 150}
    }

}
fun main(){
 val car1 = ElectricCar(maxSpeed = 195.0, VehicleCategory.SUV)
    val car2 = DieselCar(maxSpeed = 145.0, VehicleCategory.SUV)
    val listaMacchine = FleetManager
    listaMacchine.addVehicle(car1)
    listaMacchine.addVehicle(car2)
    println(listaMacchine.fastVechicleCount())

}