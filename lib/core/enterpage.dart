import 'dart:typed_data';
import 'dart:ui';

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter/cupertino.dart';

// ignore: camel_case_types
class enterPage extends StatefulWidget {
  const enterPage({super.key});

  @override
  State<enterPage> createState() => enterPageState();
}





class enterPageState extends State<enterPage> {
  double _currentSliderValue = 20;
  
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      // decoration: const BoxDecoration(color: Color.fromRGBO(230, 230, 230,0)),
      // child: Center(
        body: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
          Row(children: [
            Slider(
              value: _currentSliderValue,
              max: 100,
              divisions: 5,
              label: _currentSliderValue.round().toString(),
              onChanged: (double value) {
                setState(() {
                  _currentSliderValue = value;
                });
              },
            ),
            //Image(image: image)
          ],)
        ]),
    );
  }
}