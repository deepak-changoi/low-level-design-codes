package com.individual.CabService.repository;
import com.individual.CabService.model.Driver;

import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;
@Repository
public interface DriverRepository extends MongoRepository<Driver, String> {

}
