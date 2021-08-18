import 'package:flutter/material.dart';

class PlantDetailsPage extends StatefulWidget {
  final String imgPath;

  const PlantDetailsPage({Key? key, required this.imgPath}) : super(key: key);

  @override
  _PlantDetailsPageState createState() => _PlantDetailsPageState();
}

class _PlantDetailsPageState extends State<PlantDetailsPage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Theme.of(context).backgroundColor,
      body: Column(
        children: [
          Container(
            decoration: BoxDecoration(
              image: DecorationImage(
                fit: BoxFit.cover,
                image: AssetImage(
                  widget.imgPath,
                  // height: 400,
                ),
              ),
              borderRadius: BorderRadius.only(
                bottomLeft: Radius.circular(32),
                bottomRight: Radius.circular(32),
              ),
            ),
            height: 300,
          ),
        ],
      ),
    );
  }
}
