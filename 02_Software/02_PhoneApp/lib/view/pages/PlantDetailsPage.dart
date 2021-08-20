import 'dart:ui';

import 'package:build/models/Plant.dart';
import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'package:line_icons/line_icons.dart';

class PlantDetailsPage extends StatefulWidget {
  final Plant plant;

  const PlantDetailsPage({Key? key, required this.plant}) : super(key: key);

  @override
  _PlantDetailsPageState createState() => _PlantDetailsPageState();
}

class _PlantDetailsPageState extends State<PlantDetailsPage> {
  double _currentSliderValue = 0.1;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Theme.of(context).backgroundColor,
      body: SafeArea(
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Container(
              decoration: BoxDecoration(
                image: DecorationImage(
                  fit: BoxFit.cover,
                  image: widget.plant.image,
                ),
                // borderRadius: BorderRadius.only(
                //   bottomLeft: Radius.circular(32),
                //   bottomRight: Radius.circular(32),
                // ),
              ),
              height: 350,
            ),
            SizedBox(
              height: 16,
            ),
            Padding(
              padding: const EdgeInsets.all(8.0),
              child: Container(
                decoration: BoxDecoration(
                  borderRadius: BorderRadius.circular(16),
                  color: Colors.white,
                  boxShadow: [
                    BoxShadow(
                      spreadRadius: 0,
                      blurRadius: 8,
                      color: Color.fromARGB(15, 0, 0, 0),
                      offset: Offset(4, 4),
                    ),
                    BoxShadow(
                      spreadRadius: 0,
                      blurRadius: 8,
                      color: Color.fromARGB(15, 0, 0, 0),
                      offset: Offset(-4, -4),
                    )
                  ],
                ),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.center,
                  children: [
                    Padding(
                      padding: const EdgeInsets.all(16.0),
                      child: SafezoneIndicator(),
                    ),
                    Column(
                      crossAxisAlignment: CrossAxisAlignment.center,
                      children: [
                        Text(
                          "19°C",
                          style: TextStyle(
                            fontSize: 24,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                        Text(
                          "Current Temperature",
                          textAlign: TextAlign.left,
                          style: TextStyle(
                            color: Color(0xFFA3AED0),
                            fontSize: 12,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                        SizedBox(
                          height: 16.0,
                        )
                      ],
                    ),
                  ],
                ),
              ),
            )
          ],
        ),
      ),
    );
  }
}

class SafezoneIndicator extends StatelessWidget {
  const SafezoneIndicator({
    Key? key,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.center,
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Icon(FontAwesomeIcons.snowflake),
        Expanded(
          child: Column(
            children: [
              Stack(
                clipBehavior: Clip.none,
                children: [
                  Padding(
                    padding: const EdgeInsets.only(
                        left: 8.0, right: 8.0, bottom: 4.0, top: 9.0),
                    child: Container(
                      height: 10,
                      width: double.infinity,
                      decoration: BoxDecoration(
                        color: Colors.white,
                        gradient: LinearGradient(colors: [
                          Color(0xff60a6ff),
                          Color(0xff21c156),
                          Color(0xff21c156),
                          Color(0xffff9a4d),
                        ], stops: [
                          0.12,
                          0.22,
                          0.75,
                          0.85
                        ]),
                        boxShadow: [
                          BoxShadow(
                            spreadRadius: 0,
                            blurRadius: 8,
                            color: Color(0x20000000),
                            offset: Offset(4, 4),
                          ),
                          BoxShadow(
                            spreadRadius: 0,
                            blurRadius: 8,
                            color: Color(0x20000000),
                            offset: Offset(-4, -4),
                          )
                        ],
                        borderRadius: BorderRadius.circular(16.0),
                      ),
                    ),
                  ),
                  Container(
                    alignment: Alignment(0, 0),
                    child: Container(
                      child: Icon(
                        FontAwesomeIcons.leaf,
                        size: 24,
                        color: Color(0xFF2B3674),
                      ),
                    ),
                  ),
                  Container(
                    alignment: Alignment(-0.65, 0),
                    child: Padding(
                      padding: const EdgeInsets.only(top: 27.0),
                      child: Text(
                        "8°C",
                        style: TextStyle(fontWeight: FontWeight.bold),
                      ),
                    ),
                  ),
                  Container(
                    alignment: Alignment(0.65, 0),
                    child: Padding(
                      padding: const EdgeInsets.only(top: 27.0),
                      child: Text(
                        "30°C",
                        style: TextStyle(fontWeight: FontWeight.bold),
                      ),
                    ),
                  ),
                ],
              ),
            ],
          ),
        ),
        Icon(FontAwesomeIcons.fire),
      ],
    );
  }
}
