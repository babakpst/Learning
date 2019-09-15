import java.awt.*;

public class Car {


    // objects
    double averageMilePerGallon;
    String licensePlate;
    Color paintColor;
    boolean areTailingWorking;

    // constructor
    public Car(double inputAverageMPG, String inputLicensePlate, Color inputPaintColor, boolean inputAreTaillightsWorking){
        this.averageMilePerGallon = inputAverageMPG;
        this.licensePlate = inputLicensePlate;
        this.paintColor = inputPaintColor;
        this.areTailingWorking = inputAreTaillightsWorking;
    }


    public void chagnePaintColor(Color newPaintColor){
        this.paintColor = newPaintColor;
    }

    public double speedingUp(double currentSpeed){
        return (currentSpeed + 100);
    }

}
