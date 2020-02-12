void CruiseControl() {                       // функция круиз контроля`
  static long timeCalc;                      // для вычисления времени между появлением новых данных о скорости
  REGULATOR.setpoint = presetSpeed;          // отправляем в регулятор установленную скорость
  if (TEST_TIMER.isReady()) {
    //REGULATOR.setDt(millis()-timeCalc);      // устанавилваем dt ПИДа равным времени обновления данных о скорости
   // Serial.println(millis()-timeCalc);
    //timeCalc = millis();                     // засекаем время
    newSpeedFlag = 0;                        // опускаем флаг новых данных о скорости    
    REGULATOR.input = currentSpeed;          // отправляем в регулятор текущую скорость
    if (currentSpeed < presetSpeed) {        // если текущая скорость меньше установленной
      REGULATOR.setDirection(NORMAL);        // включаем прямое регулирование ПИДа
      DAC_BRAKE.setVoltage(MIN_REGULATOR_OUT * 10, false);        // устанавливаем выход ЦАП тормоза в 0
      DAC_ACCEL.setVoltage(map (REGULATOR.getResult(), 0 , 500, 800, 3700), false);          // регулируем скорость ЦАПом газа
    }
     if (currentSpeed > presetSpeed){          // если текущая скорость больше установленной
      REGULATOR.setDirection(REVERSE);          // включаем обоатное регулирование ПИДа
    DAC_ACCEL.setVoltage(MIN_REGULATOR_OUT * 10, false);          // устанавливаем выход ЦАП газа в 0
      DAC_BRAKE.setVoltage(map (REGULATOR.getResult(),0 , 500, 800, 3700), false);           // регулируем скорость ЦАПом тормоза
     }
       Serial.print(presetSpeed);
    Serial.print(",");
    Serial.print(currentSpeed);
    Serial.println(",");
  }
  //if (TEST_TIMER.isReady()) {
  

  //}
}
