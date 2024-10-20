package com.individual.CabService.model;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document(collection = "rides")
public class Ride {

    @Id
    private String rideId;
    private Passenger passenger;
    private Driver driver;
    private Cab cab;
    private Location startLocation;
    private Location endLocation;
    private String status;
    private double fare;

    public Ride(){}

    public Ride(Passenger passenger ,Driver driver, Ride ride, Cab cab ,Location startLocation , Location endLocation )
    {
        this.rideId = java.util.UUID.randomUUID().toString();
        this.passenger = passenger;
        this.driver = driver;
        this.cab = cab;
        this.startLocation = startLocation;
        this.endLocation = endLocation;
        this.status = "REQUESTED";
        this.fare = 0.0;
    }

    // Getters and Setters
    public String getRideId() {
        return rideId;
    }

    public void setRideId(String rideId) {
        this.rideId = rideId;
    }

    public Passenger getPassenger() {
        return passenger;
    }

    public void setPassenger(Passenger passenger) {
        this.passenger = passenger;
    }

    public Driver getDriver() {
        return driver;
    }

    public void setDriver(Driver driver) {
        this.driver = driver;
    }

    public Cab getCab() {
        return cab;
    }

    public void setCab(Cab cab) {
        this.cab = cab;
    }

    public Location getStartLocation() {
        return startLocation;
    }

    public void setStartLocation(Location startLocation) {
        this.startLocation = startLocation;
    }

    public Location getEndLocation() {
        return endLocation;
    }

    public void setEndLocation(Location endLocation) {
        this.endLocation = endLocation;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public double getFare() {
        return fare;
    }

    public void setFare(double fare) {
        this.fare = fare;
    }
}
