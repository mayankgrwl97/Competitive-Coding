import junit.framework.TestCase;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

/**
 * A JUnit test case class.
 * Every method starting with the word "test" will be called when running
 * the test with JUnit.
 */
public class DecompressTest extends TestCase {
  ByteArrayOutputStream testOutput; 
  void setup() { 
    testOutput  = new ByteArrayOutputStream();
    PrintStream ps = new PrintStream(testOutput);
    System.setOut(ps);
  }
  /**
   * A test method.
   * (Replace "X" with a name describing the test.  You may write as
   * many "testSomething" methods in this class as you wish, and each
   * one will be called when running JUnit over this class.)
   */
  public void testReadCount() {
    int count = RLdecompress.readCount("abc#d123efg",5); 
    assertTrue("Expected 123 got "+count,  count == 123);
  }
  public void testReadCountAndPrintRun() {
    setup();
    int index = RLdecompress.readCountAndPrintRun("abc#d12efg",5, 'd');
    assertTrue("Expected 7 got "+index,  index == 7);
    assertTrue("Expected dddddddddddd got "+testOutput, testOutput.toString().equals("dddddddddddd"));
  }
  public void testProcessHash() {
    setup();
    int index = RLdecompress.processHash("abc#d12efg",4);
    assertTrue("Expected 7 got "+index,  index == 7);
    assertTrue("Expected dddddddddddd got "+testOutput, testOutput.toString().equals("dddddddddddd"));
  }
  public void testProcessHash2() {
    setup();
    int index = RLdecompress.processHash("abc###d12efg",4);
    assertTrue("Expected 6 got "+index,  index == 6);
    assertTrue("Expected # got "+testOutput, testOutput.toString().equals("#"));
  }
  public void testProcessHash3() {
    setup();
    int index = RLdecompress.processHash("#a3##!12efg",4);
    assertTrue("Expected 6 got "+index,  index == 6);
    assertTrue("Expected ! got "+testOutput, testOutput.toString().equals("!"));
  }
  public void testProcessOneLine() {
    setup();
    RLdecompress.processOneLine("#f3!45#63##!ab#c4#!3def");
    assertTrue("Expected fff45666!abcccc!!!def got "+testOutput, testOutput.toString().trim().equals("fff45666!abcccc!!!def"));
  }  
}