/*
  Copyright (C) 2018 - 2021 by the authors of the World Builder code.

  This file is part of the World Builder.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef WORLD_BUILDER_FEATURES_SUBDUCTING_PLATE_MODELS_GRAINS_RANDOM_UNIFORM_DISTRIBUTION_H
#define WORLD_BUILDER_FEATURES_SUBDUCTING_PLATE_MODELS_GRAINS_RANDOM_UNIFORM_DISTRIBUTION_H


#include "world_builder/features/subducting_plate_models/grains/interface.h"

namespace WorldBuilder
{

  namespace Features
  {
    namespace SubductingPlateModels
    {
      namespace Grains
      {
        /**
         * This class represents a continental plate and can implement
         * submodules for temperature and grains. These submodules determine
         * what the returned temperature or grains of the temperature and grains
         * functions of this class will be.
         */
        class RandomUniformDistribution final: public Interface
        {
          public:
            /**
             * constructor
             */
            RandomUniformDistribution(WorldBuilder::World *world);

            /**
             * Destructor
             */
            ~RandomUniformDistribution() override final;

            /**
             * declare and read in the world builder file into the parameters
             * class
             */
            static void declare_entries(Parameters &prm,
                                        const std::string &parent_name = "");

            /**
             * declare and read in the world builder file into the parameters
             * class
             */
            static void declare_grain_size_model_entries(
              Parameters &prm, const std::string &parent_name,
              const std::vector<std::string> &required_entries);

            /**
             * declare and read in the world builder file into the parameters
             * class
             */
            static void
            declare_fixed_size_model_entries(Parameters &prm,
                                             const std::string &parent_name = "");

            /**
             * declare and read in the world builder file into the parameters
             * class
             */
            void parse_entries(Parameters &prm) override final;

            /**
             * Returns a grains based on the given position, composition (e.g.
             * olivine and/or enstatite)depth in the model, gravity and current grains.
             */
            WorldBuilder::grains
            get_grains(const Point<3> &position,
                       const double depth,
                       const unsigned int composition_number,
                       WorldBuilder::grains grains,
                       const double feature_min_depth,
                       const double feature_max_depth,
                       const WorldBuilder::Utilities::PointDistanceFromCurvedPlanes &distance_from_planes,
                       const AdditionalParameters &additional_parameters) const override final;

          private:
            // uniform grains submodule parameters
            double min_depth;
            double max_depth;
            std::vector<unsigned int> grains;
            std::vector<unsigned int> compositions;
            std::string operation;
            std::vector<double> grain_sizes;
            std::vector<bool> normalize_grain_sizes;
        };
      } // namespace Grains
    }   // namespace SubductingPlateModels
  }     // namespace Features
} // namespace WorldBuilder

#endif
