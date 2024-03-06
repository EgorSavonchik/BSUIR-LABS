package org.example;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;
import triangle.Triangle;

/**
 * Unit test for simple App.
 */
public class AppTest extends TestCase
{
    private double parameterA, parameterB, parameterC;

    protected void setUp() throws Exception {
        super.setUp();
        // Вы можете поместить сюда код, который должен быть выполнен перед каждым тестом
    }

    protected void tearDown() throws Exception {
        super.tearDown();
        // Вы можете поместить сюда код, который должен быть выполнен после каждого теста
    }

    public void testCheckTriangle_Correct_tst() {
        parameterA = 15;
        parameterB = 12;
        parameterC = 14;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertTrue(triangle.checkTriangle());

    }

    public void testCheckTriangle_Zero_A_tst(){
        parameterA = 0;
        parameterB = 12;
        parameterC = 14;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testCheckTriangle_Zero_B_tst(){
        parameterA = 15;
        parameterB = 0;
        parameterC = 14;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testCheckTriangle_Zero_C_tst(){
        parameterA = 15;
        parameterB = 12;
        parameterC = 0;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testCheckTriangle_Negative_A_tst(){
        parameterA = -15;
        parameterB = 12;
        parameterC = 14;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testCheckTriangle_Negative_B_tst(){
        parameterA = 15;
        parameterB = -12;
        parameterC = 14;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testCheckTriangle_Negative_C_tst(){
        parameterA = 15;
        parameterB = 12;
        parameterC = -14;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testCheckTriangle_Three_More_C_tst(){
        parameterA = 15;
        parameterB = 12;
        parameterC = 14;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertTrue(triangle.checkTriangle());
    }

    public void testCheckTriangle_Three_More_B_tst(){
        parameterA = 15;
        parameterB = 12;
        parameterC = 14;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertTrue(triangle.checkTriangle());
    }

    public void testCheckTriangle_Three_More_A_tst(){
        parameterA = 15;
        parameterB = 12;
        parameterC = 14;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertTrue(triangle.checkTriangle());
    }

    public void testCheckTriangle_Three_Less_C_tst(){
        parameterA = 1;
        parameterB = 2;
        parameterC = 14;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testCheckTriangle_Three_Less_B_tst(){
        parameterA = 5;
        parameterB = 12;
        parameterC = 1;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testCheckTriangle_Three_Less_A_tst(){
        parameterA = 15;
        parameterB = 1;
        parameterC = 1;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testCheckTriangle_Three_Equal_C_tst(){
        parameterA = 5;
        parameterB = 5;
        parameterC = 10;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testCheckTriangle_Three_Equal_B_tst(){
        parameterA = 5;
        parameterB = 10;
        parameterC = 5;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testCheckTriangle_Three_Equal_A_tst(){
        parameterA = 10;
        parameterB = 5;
        parameterC = 5;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testDetectTriangle_Restangular_1_tst(){
        parameterA = 3;
        parameterB = 4;
        parameterC = 5;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.detectTriangle(), 8);
    }

    public void testDetectTriangle_Restangular_2_tst(){
        parameterA = 5;
        parameterB = 4;
        parameterC = 3;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.detectTriangle(), 8);
    }

    public void testDetectTriangle_Restangular_3_tst(){
        parameterA = 2;
        parameterB = 5;
        parameterC = 4;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.detectTriangle(), 8);
    }

    public void testDetectTriangle_Equilateral_tst(){
        parameterA = 2;
        parameterB = 2;
        parameterC = 2;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.detectTriangle(), 0);
    }

    public void testDetectTriangle_Isosceles_1_tst(){
        parameterA = 2;
        parameterB = 2;
        parameterC = 3;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.detectTriangle(), 2);
    }

    public void testDetectTriangle_Isosceles_2_tst(){
        parameterA = 3;
        parameterB = 2;
        parameterC = 2;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.detectTriangle(), 2);
    }

    public void testDetectTriangle_Isosceles_3_tst(){
        parameterA = 2;
        parameterB = 3;
        parameterC = 2;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.detectTriangle(), 2);
    }

    public void testDetectTriangle_Isosceles_Restangular_tst(){
        parameterA = 2;
        parameterB = 2;
        parameterC = 2 * Math.sqrt(2);
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.detectTriangle(), 0);
    }

    public void testDetectTriangle_Ordinary_tst(){
        parameterA = 1;
        parameterB = 3;
        parameterC = 8* Math.sqrt(2);
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.detectTriangle(), 4);
    }

    public void testDetectTriangle_Rectangular_Ordinary_tst(){
        parameterA = 3;
        parameterB = 4;
        parameterC = 5;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.detectTriangle(), 8);
    }

    public void testCheckTriangle_MaxValue_tst(){
        parameterA = Double.MAX_VALUE;
        parameterB = Double.MAX_VALUE;
        parameterC = Double.MAX_VALUE;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertTrue(triangle.checkTriangle());
    }

    public void testCheckTriangle_NaN_tst(){
        parameterA = 0.0/0.0;
        parameterB = 1.0/0.0;
        parameterC = 0.0/0.0;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testCheckTriangle_All_Negative_Sides_tst(){
        parameterA = -1;
        parameterB = -1;
        parameterC = -1;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertFalse(triangle.checkTriangle());
    }

    public void testDetectTriangle_IsoscelesAndRectangular_tst(){
        parameterA = 4;
        parameterB = 4;
        parameterC = 4*Math.sqrt(2);
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.detectTriangle(), 10);
    }

    public void testGetSquare_Equilateral_tst(){
        parameterA = 4;
        parameterB = 4;
        parameterC = 4;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.getSquare(), 6.9282032302755091741097853660235);
    }

    public void testGetSquare_Rectangular_tst(){
        parameterA = 4*Math.sqrt(2);
        parameterB = 4*Math.sqrt(2);
        parameterC = 8;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(Math.round(triangle.getSquare()), 16);
    }

    public void testGetSquare_Ordinary_tst(){
        parameterA = 3;
        parameterB = 4;
        parameterC = 2;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.getSquare(), 2.9047375096555625);
    }

    public void testGetSquare_ZeroArea_tst(){
        parameterA = 3;
        parameterB = 1;
        parameterC = 2;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.getSquare(), 0.0);
    }

    public void testGetSquare_IncorrectTriangle_tst(){
        parameterA = 5;
        parameterB = 1;
        parameterC = 2;
        Triangle triangle = new Triangle(parameterA, parameterB, parameterC);
        assertEquals(triangle.getSquare(), 0.0/0.0);
    }
}
