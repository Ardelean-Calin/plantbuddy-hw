import 'dart:developer';
import 'dart:math';

import 'package:build/view/pages/PlantDetailsPage.dart';
import 'package:flutter/material.dart';
import 'package:modal_bottom_sheet/modal_bottom_sheet.dart';
import 'package:build/models/Plant.dart';

class PlantCardSmall extends StatefulWidget {
  final Plant plantObj;

  const PlantCardSmall({Key? key, required this.plantObj}) : super(key: key);

  @override
  _PlantCardSmallState createState() => _PlantCardSmallState();
}

class _PlantCardSmallState extends State<PlantCardSmall> {
  final Color shadowColor = [
    Color.fromARGB(30, 255, 0, 0),
    Color.fromARGB(15, 0, 0, 0)
  ][Random().nextInt(2)];

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: () => showCupertinoModalBottomSheet(
        context: context,
        backgroundColor: Theme.of(context).backgroundColor,
        builder: (context) => PlantDetailsPage(imgObj: widget.plantObj.image),
      ),
      child: SizedBox(
        height: 365,
        // width: 350,
        child: Container(
          decoration: BoxDecoration(
            borderRadius: BorderRadius.circular(32),
            color: Colors.white,
            boxShadow: [
              BoxShadow(
                spreadRadius: 0,
                blurRadius: 8,
                color: shadowColor,
                offset: Offset(4, 4),
              ),
              BoxShadow(
                spreadRadius: 0,
                blurRadius: 8,
                color: shadowColor,
                offset: Offset(-4, -4),
              )
            ],
          ),
          child: Stack(
            children: [
              Align(
                alignment: Alignment.topRight,
                child: Padding(
                  padding: const EdgeInsets.all(16.0),
                  child: Icon(
                    [
                      Icons.bluetooth_disabled_outlined,
                      null
                    ][Random().nextInt(2)],
                    size: 24,
                    color: Color(0xFFA3AED0),
                  ),
                ),
              ),
              Column(
                mainAxisAlignment: MainAxisAlignment.spaceAround,
                children: [
                  Container(
                    width: 190,
                    height: 190,
                    decoration: BoxDecoration(
                      shape: BoxShape.circle,
                      image: DecorationImage(
                        fit: BoxFit.cover,
                        image: widget.plantObj.image,
                      ),
                      // height: 130,
                    ),
                  ),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Column(
                        children: [
                          Text(
                            widget.plantObj.name,
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
                              widget.plantObj.location,
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
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Column(
                        mainAxisAlignment: MainAxisAlignment.center,
                        children: [
                          Text(
                            "Air",
                            style: TextStyle(
                              color: Color(0xFFA3AED0),
                              fontSize: 12,
                            ),
                          ),
                          Icon(
                            Icons.air,
                            color: Colors.amber,
                            size: 32,
                          ),
                          Text(
                            "Warm",
                            style: TextStyle(
                              color: Color(0xFFA3AED0),
                              fontSize: 12,
                            ),
                          ),
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
                          ),
                          Text(
                            "Shade",
                            style: TextStyle(
                              color: Color(0xFFA3AED0),
                              fontSize: 12,
                            ),
                          ),
                        ],
                      ),
                      WaterTag(),
                    ],
                  )
                ],
              ),
            ],
          ),
          // color: Colors.red,
        ),
      ),
    );
  }
}

class WaterTag extends StatelessWidget {
  const WaterTag({
    Key? key,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        Text(
          "Water",
          style: TextStyle(
            color: Color(0xFFA3AED0),
            fontSize: 12,
          ),
        ),
        Icon(
          Icons.water,
          color: Colors.lightGreen,
          size: 32,
        ),
        Text(
          "3d ago",
          style: TextStyle(
            color: Color(0xFFA3AED0),
            fontSize: 12,
          ),
        ),
      ],
    );
  }
}
