package com.individual.CabService.model;

public class Payment {

    private String paymentId;
    private String rideId;
    private String passengerId;
    private double amount;
    private String paymentMethod;  // e.g., CREDIT_CARD, DEBIT_CARD, PAYPAL

    public Payment() {}

    public Payment(String rideId, String passengerId, double amount, String paymentMethod) {
        this.paymentId = java.util.UUID.randomUUID().toString();
        this.rideId = rideId;
        this.passengerId = passengerId;
        this.amount = amount;
        this.paymentMethod = paymentMethod;
    }

}
