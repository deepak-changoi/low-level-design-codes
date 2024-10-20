package com.individual.CabService.repository;

import com.individual.CabService.model.Cab;

import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;
@Repository
public interface CabRepository extends MongoRepository<Cab, String> {

}
