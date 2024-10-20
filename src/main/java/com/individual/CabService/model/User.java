package com.individual.CabService.model;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;
@Document(collection = "users")
public class User {

    @Id
    private String userId;
    private String name;
    private String email;
    private String phoneNumber;

    public User(){}

    public User(String name , String email, String phoneNumber)
    {
        this.name = name;
        this.email = email;
        this.phoneNumber = phoneNumber;
    }
}
