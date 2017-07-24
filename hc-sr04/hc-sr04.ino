int interval = 0;
double distance = 0;

void setup() {
    pinMode( 2, OUTPUT );
    pinMode( 3, INPUT );
    Serial.begin( 9600 );
}

void loop() {

    if ( Serial.available() > 0 ) {

        Serial.read();

        // pulse !
        digitalWrite( 2, HIGH );
        delayMicroseconds( 100 );
        digitalWrite( 2, LOW );

        // mesure the interval 
        interval = pulseIn( 3, HIGH );

        distance = interval * 0.017; // cm 

        Serial.print( interval, DEC );
        Serial.print( "\t" );
        Serial.print( distance, 4 );
        Serial.print( "\n" );
    }
}
