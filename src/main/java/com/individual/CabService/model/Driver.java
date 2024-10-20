package com.individual.CabService.model;
import org.springframework.data.mongodb.core.mapping.Document;

@Document(collection = "drivers")
public class Driver extends User{

    private String licenseNumber;

    public Driver(){}

    public Driver(String name , String email, String phoneNumber , String licenseNumber){
        super(name , email , phoneNumber);
        this.licenseNumber = licenseNumber;
    }

    public String getLicenseNumber()
    {
        return licenseNumber;
    }

    public void setLicenseNumber(String licenseNumber)
    {
        this.licenseNumber = licenseNumber;
    }
}

