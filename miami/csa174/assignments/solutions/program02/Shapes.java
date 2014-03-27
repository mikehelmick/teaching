// Mike Helmick
// Program 3 solutions
// Calculate some information about 5 solid objects

public class Shapes {
 
    public static void main( String[] args ) {
     
        // cube
        double cubeLength = 4.25;
        double cubeArea = 6 * cubeLength * cubeLength;
        double cubeVolume = cubeLength * cubeLength * cubeLength;
        
        System.out.println("For a cube with side lengths of " + cubeLength );
        System.out.println(" The surface area is: " + cubeArea );
        System.out.println(" The volume is: " + cubeVolume );
        
        // sphere
        double sphereRadius = 22.3;
        double sphereArea = 4 * Math.PI * sphereRadius * sphereRadius;
        double sphereVolume = 4.0 / 3.0 * Math.PI * sphereRadius * sphereRadius * sphereRadius;
        
        System.out.println("For a sphere with a radius of " + sphereRadius );
        System.out.println(" The surface area is: " + sphereArea );
        System.out.println(" The volume is: " + sphereVolume );
        
        // cylinder
        double cylinderRadius = 2;
        double cylinderHeight = 4.75;
        
        double cylinderEndArea = Math.PI * cylinderRadius * cylinderRadius;
        double cylinderArea = 2 * cylinderEndArea + 
                              2 * Math.PI * cylinderRadius * cylinderHeight;
        double cylinderVolume = Math.PI * cylinderRadius * cylinderRadius * cylinderHeight;
        
        System.out.println("For a cylinder with a radius of " + cylinderRadius + " and a height of " + cylinderHeight );
        System.out.println(" The surface area is: " + cylinderArea );
        System.out.println(" The volume is: " + cylinderVolume );
                             
        // dodecahedron
        double dodecaSide = 5.0;
        
        double dodecaArea = 3 * Math.sqrt( 25 + 10 * Math.sqrt(5) ) * dodecaSide * dodecaSide;
        double dodecaVolume = 1/4.0 * (15 + 7 * Math.sqrt(5)) * dodecaSide * dodecaSide * dodecaSide;
        
        System.out.println("For a dodecahedron with a side of " + dodecaSide );
        System.out.println(" The surface area is: " + dodecaArea );
        System.out.println(" The volume is: " + dodecaVolume );
        
        // icosahedron
        double icosaSide = 7.25;
        
        double icosaArea = 5 * Math.sqrt(3) * icosaSide * icosaSide;
        double icosaVolume = 5.0 / 12 * (3 + Math.sqrt(5)) * icosaSide * icosaSide * icosaSide;
 
        System.out.println("For a icosahedron with a side of " + icosaSide );
        System.out.println(" The surface area is: " + icosaArea );
        System.out.println(" The volume is: " + icosaVolume );
        
    }
    
}