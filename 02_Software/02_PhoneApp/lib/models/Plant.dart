import 'package:build/models/PlantConditions.dart';
import 'package:flutter/rendering.dart';

class Plant {
  late String name;
  late String location;
  late AssetImage image;

  late int _airTemperature;
  late int _airHumidity;
  late int _soilWaterContent;
  late int _illuminance;

  late PlantConditions? conditions;

  // Constructor
  Plant({
    required String name,
    required String location,
    required AssetImage image,
    PlantConditions? conditions,
  }) {
    this.name = name;
    this.location = location;
    this.conditions = conditions;
    this.image = image;
  }

  /* Getters and setters BEGIN */
  // For the illuminance measured in Lux
  int get illuminance => this._illuminance;
  set illuminance(int illuminance) {
    this._illuminance = illuminance;
  }

  // For the air temperature measured in Celsius
  int get airTemperature => this._airTemperature;
  set airTemperature(int airTemperature) {
    this._airTemperature = airTemperature;
  }

  // For the relatieve air humidity measured in %
  int get airHumidity => this._airHumidity;
  set airHumidity(int airHumidity) {
    this._airHumidity = airHumidity;
  }

  // For the Soil water content measured in %
  int get soilWaterContent => this._soilWaterContent;
  set soilWaterContent(int soilWaterContent) {
    this._soilWaterContent = soilWaterContent;
  }
  /* Getters and setters END */
}
