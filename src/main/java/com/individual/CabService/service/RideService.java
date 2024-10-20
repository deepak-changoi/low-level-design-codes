package com.individual.CabService.service;


import com.individual.CabService.model.Ride;
import com.individual.CabService.repository.RideRepository;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Optional;

@Service
public class RideService {

    @Autowired
    private RideRepository rideRepository;

    public Ride requestRide(Ride rideRequest)
    {
        return rideRepository.save(rideRequest); // saving to MongoDB
    }

    public Ride startRide(String rideId)
    {
        Optional<Ride> rideOpt = rideRepository.findById(rideId);

        if(rideOpt.isEmpty()){
            throw new RuntimeException("Ride not found");
        }

        Ride ride = rideOpt.get();
        ride.setStatus("IN_PROGRESS");
        return rideRepository.save(ride); // update to MongoDB database
    }

    public Ride updateRide(String rideId , double newLatitude, double newLongitude)
    {
        Optional<Ride> rideOpt = rideRepository.findById(rideId);

        if(rideOpt.isEmpty())
        {
            throw new RuntimeException("Ride not found");
        }

        Ride ride = rideOpt.get();
        ride.getEndLocation().setLatitude(newLatitude);
        ride.getEndLocation().setLongitude(newLongitude);

        return rideRepository.save(ride);
    }

    public void cancelRide(String rideId)
    {
        Optional<Ride> rideOpt = rideRepository.findById(rideId);
        if(rideOpt.isEmpty())
        {
            throw new RuntimeException("Ride not found");
        }

        Ride ride = rideOpt.get();
        ride.setStatus("CANCELED");
        rideRepository.save(ride);
    }

    public double checkPrice(String rideId){
        Optional<Ride> rideOpt = rideRepository.findById(rideId);
        if(rideOpt.isEmpty()){
            throw new RuntimeException("Ride not found");
        }

        Ride ride = rideOpt.get();
        return ride.getFare();
    }
}
