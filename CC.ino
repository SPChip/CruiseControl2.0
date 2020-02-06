void CruiseControl(){   // функция круиз контроля
  REGULATOR.setpoint = presetSpeed;  // отправляем в регулятор установленную скорость
  REGULATOR.input = currentSpeed;    // отправляем в регулятор текущую скорость
  if (currentSpeed < presetSpeed){   // если текущая скорость меньше установленной
   REGULATOR.setDirection(NORMAL);   // включаем прямое регулирование ПИДа
   DAC_BRAKE.setVoltage(0, false);   // устанавливаем выход ЦАП тормоза в 0
   DAC_ACCEL.setVoltage(REGULATOR.getResultTimer(), false);   // регулируем скорость ЦАПом газа
  }
  if (currentSpeed > presetSpeed){   // если текущая скорость больше установленной
   REGULATOR.setDirection(REVERSE);  // включаем обоатное регулирование ПИДа
   DAC_ACCEL.setVoltage(0, false);   // устанавливаем выход ЦАП газа в 0
   DAC_BRAKE.setVoltage(REGULATOR.getResultTimer(), false);   // регулируем скорость ЦАПом тормоза
  }
}
