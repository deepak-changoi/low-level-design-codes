package com.individual.CabService.model;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document(collection = "cabs")
public class Cab {

    @Id
    private String cabId;
    private String cabNumber;
    private String model;
    private String color;

    public Cab(){}

    public Cab(String cabNumber, String model , String color)
    {
        this.cabNumber = cabNumber;
        this.model = model;
        this.color = color;
    }



}
