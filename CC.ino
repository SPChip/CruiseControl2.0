void CruiseControl(){   // функция круиз контроля
  REGULATOR.setpoint = presetSpeed;  // отправляем в регулятор установленную скорость
  REGULATOR.input = currentSpeed;    // отправляем в регулятор текущую скорость
  if (currentSpeed < presetSpeed){   // если текущая скорость меньше установленной
   REGULATOR.setDirection(NORMAL);   // включаем прямое регулирование ПИДа
   DAC_BRAKE.setVoltage(MIN_REGULATOR_OUT*10, false);   // устанавливаем выход ЦАП тормоза в 0
   DAC_ACCEL.setVoltage(map (REGULATOR.getResultTimer(),0 , 500, 800, 3700), false);   // регулируем скорость ЦАПом газа
   
  }
 // if (currentSpeed > presetSpeed){   // если текущая скорость больше установленной
 //  REGULATOR.setDirection(REVERSE);  // включаем обоатное регулирование ПИДа
   DAC_ACCEL.setVoltage(MIN_REGULATOR_OUT*10, false);   // устанавливаем выход ЦАП газа в 0
//  DAC_BRAKE.setVoltage(map (REGULATOR.getResultTimer(),0 , 500, 800, 3700), false);   // регулируем скорость ЦАПом тормоза
//  }
  //Serial.println(REGULATOR.getResultTimer());
   if (TEST_TIMER.isReady()) {
  Serial.print(presetSpeed);
  Serial.print(",");
  Serial.print(currentSpeed);
Serial.println(",");

   }
}
