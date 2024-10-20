package com.individual.CabService.repository;

import com.individual.CabService.model.Passenger;

import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;
@Repository
public interface PassengerRepository extends MongoRepository<Passenger, String> {

}
