import 'package:flutter/material.dart';

class PlantCardSmall extends StatefulWidget {
  final String plantName;
  final String imgPath;
  final String location;

  const PlantCardSmall(
      {Key? key,
      required this.plantName,
      required this.imgPath,
      required this.location})
      : super(key: key);

  @override
  _PlantCardSmallState createState() => _PlantCardSmallState();
}

class _PlantCardSmallState extends State<PlantCardSmall> {
  @override
  Widget build(BuildContext context) {
    return SizedBox(
      height: 345,
      // width: 350,
      child: Container(
        decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(32),
          color: Colors.white,
          // boxShadow: [
          //   BoxShadow(
          //     spreadRadius: 0,
          //     blurRadius: 4,
          //     color: Color.fromARGB(30, 0, 0, 0),
          //     offset: Offset(0, 4),
          //   )
          // ],
        ),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceAround,
          children: [
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Container(
                  width: 190,
                  height: 190,
                  decoration: BoxDecoration(
                    shape: BoxShape.circle,
                    image: DecorationImage(
                      fit: BoxFit.cover,
                      image: AssetImage(widget.imgPath),
                    ),
                    // height: 130,
                  ),
                )
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Column(
                  children: [
                    Text(
                      widget.plantName,
                      style: TextStyle(
                        fontWeight: FontWeight.bold,
                        fontSize: 24,
                      ),
                    ),
                    Row(children: [
                      Icon(
                        Icons.location_on_outlined,
                        color: Color(0xFFA3AED0),
                      ),
                      Text(
                        widget.location,
                        style: TextStyle(
                          fontSize: 14,
                          color: Color(0xFFA3AED0),
                        ),
                      ),
                    ])
                  ],
                )
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceAround,
              children: [
                Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      "Temperature",
                      style: TextStyle(
                        color: Color(0xFFA3AED0),
                        fontSize: 12,
                      ),
                    ),
                    Icon(
                      Icons.thermostat,
                      color: Colors.lightGreen,
                      size: 32,
                    )
                  ],
                ),
                Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      "Humidity",
                      style: TextStyle(
                        color: Color(0xFFA3AED0),
                        fontSize: 12,
                      ),
                    ),
                    Icon(
                      Icons.water,
                      color: Colors.amberAccent,
                      size: 32,
                    )
                  ],
                ),
                Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      "Light",
                      style: TextStyle(
                        color: Color(0xFFA3AED0),
                        fontSize: 12,
                      ),
                    ),
                    Icon(
                      Icons.wb_sunny,
                      color: Colors.lightGreen,
                      size: 32,
                    )
                  ],
                ),
                Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      "Soil",
                      style: TextStyle(
                        color: Color(0xFFA3AED0),
                        fontSize: 12,
                      ),
                    ),
                    Icon(
                      Icons.spa_rounded,
                      color: Colors.lightGreen,
                      size: 32,
                    )
                  ],
                ),
              ],
            )
          ],
        ),
        // color: Colors.red,
      ),
    );
  }
}
