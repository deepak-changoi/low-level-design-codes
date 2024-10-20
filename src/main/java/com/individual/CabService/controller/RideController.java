package com.individual.CabService.controller;

import com.individual.CabService.model.Ride;
import com.individual.CabService.service.RideService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/rides")
public class RideController {

    @Autowired
    private RideService rideService;

    @PostMapping("/request")
    public ResponseEntity<Ride> requestRide(@RequestBody Ride rideRequest)
    {
        Ride ride = rideService.requestRide(rideRequest);
        return ResponseEntity.ok(ride);
    }

    @PostMapping("/start/{rideId}")
    public ResponseEntity<Ride> startRide(@PathVariable String rideId)
    {
        Ride ride = rideService.startRide(rideId);
        return ResponseEntity.ok(ride);
    }

    @PutMapping("/update/{rideId}")
    public ResponseEntity<Ride> updateRide(@PathVariable String rideId, @RequestParam double newLatitude , @RequestParam double newLongitude)
    {
        Ride ride = rideService.updateRide(rideId, newLatitude , newLongitude);
        return ResponseEntity.ok(ride);
    }

    @PostMapping("/cancel/{rideId}")
    public ResponseEntity<String> cancelRide(@PathVariable String rideId)
    {
        rideService.cancelRide(rideId);
        return ResponseEntity.ok("Ride Cancelled Successfully");
    }

    @GetMapping("/check-price/{rideId}")
    public ResponseEntity<Double> checkPrice(@PathVariable String rideId)
    {
        double price = rideService.checkPrice(rideId);
        return ResponseEntity.ok(price);
    }
}
